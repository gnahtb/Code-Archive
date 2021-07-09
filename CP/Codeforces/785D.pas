const
  module=trunc(1e9)+7;
var
  f,x,y:array[0..200005] of int64;
  n,ans:int64;
  s:string;

procedure prep;
var
  i:longint;
begin
  fillchar(f,sizeof(f),0);
  f[0]:=1;
  for i:=1 to n do f[i]:=f[i-1]*i mod module;
end;

procedure init;
var
  i:longint;
begin
  fillchar(x,sizeof(x),0);
  fillchar(y,sizeof(y),0);
  for i:=1 to n do
    begin
      x[i]:=x[i-1];
      if s[i]='(' then inc(x[i]);
    end;
  for i:=n downto 1 do
    begin
      y[i]:=y[i+1];
      if s[i]=')' then inc(y[i]);
    end;
end;

function mulDaC(a,b:int64):int64;
var
  res,tmp:int64;
begin
  if b=0 then exit(1);
  tmp:=mulDaC(a,b div 2);
  res:=sqr(tmp) mod module;
  if odd(b) then res:=res*a mod module;
  mulDaC:=res;
end;

procedure solve;
var
  i:longint;
  t1,t2,t3:int64;
begin
  ans:=0;
  for i:=1 to n do
    if s[i]='(' then
      begin
        t1:=f[x[i]+y[i]-1];
        t2:=mulDaC(f[x[i]],module-2);
        t3:=mulDaC(f[y[i]-1],module-2);
        t2:=t2*t3 mod module;
        t1:=t1*t2 mod module;
        ans:=(ans+t1) mod module;
      end;
end;

begin
  readln(s);
  n:=length(s);
  prep;
  init;
  solve;
  writeln(ans);
end.
