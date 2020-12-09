{$H+}
const
  module=trunc(1E9)+7;
var
  a,b:string;
  n:longint;
  ans:int64;
  f,fi:array[0..1000005] of int64;
  cnt:array['a'..'z'] of int64;

function pow(a,b:int64):int64;
var
  res:int64;
begin
  if b=0 then exit(1);
  res:=sqr(pow(a,b >> 1)) mod module;
  if b and 1=1 then res:=res*a mod module;
  pow:=res;
end;

procedure prep;
var
  i:longint;
begin
  f[0]:=1;
  fi[0]:=1;
  for i:=1 to n do
    begin
      f[i]:=f[i-1]*int64(i) mod module;
      fi[i]:=pow(f[i],module-2);
    end;
end;

function countLess(limit:string):int64;
var
  res,sum,dif,tmp:int64;
  i:longint;
  j,x:char;
  cur:array['a'..'z'] of int64;
begin
  res:=0;
  for j:='a' to 'z' do cur[j]:=cnt[j];
  for i:=1 to n do
    begin
      sum:=0;
      dif:=1;
      for j:='a' to 'z' do
        if cur[j]>1 then dif:=dif*fi[cur[j]] mod module;
      for j:='a' to chr(ord(limit[i])-1) do
        if cur[j]>0 then
          begin
            tmp:=f[n-i]*dif mod module*f[cur[j]] mod module*fi[cur[j]-1] mod module;
            sum:=(sum+tmp) mod module;
          end;
      res:=(res+sum) mod module;
      x:=#0;
      for j:='a' to limit[i] do if cur[j]>0 then x:=j;
      if x<limit[i] then break;
      dec(cur[x]);
    end;
  countLess:=res;
end;

procedure solve;
var
  i:longint;
  c1,c2:int64;
begin
  fillchar(cnt,sizeof(cnt),0);
  for i:=1 to n do inc(cnt[a[i]]);
  c1:=countLess(a);
  c2:=countLess(b);
  ans:=(c2-c1-1+module+module) mod module;
end;

begin
  readln(a);
  readln(b);
  n:=length(a);
  prep;
  solve;
  writeln(ans);
end.
