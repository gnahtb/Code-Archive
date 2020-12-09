const
  module=trunc(1E9)+7;
type
  TCoor=record row,col:int64; end;
var
  a:array[0..2005] of TCoor;
  f,fi,p:array[0..200005] of int64;
  h,w,n,ans:int64;

procedure enter;
var
  i:longint;
begin
  readln(h,w,n);
  for i:=1 to n do
    with a[i] do readln(row,col);
end;

procedure sort;
var
  i,j:longint;
  t:TCoor;
begin
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (a[i].row>a[j].row) or ((a[i].row=a[j].row) and (a[i].col>a[j].col)) then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
        end;
end;

function pow(a,b:int64):int64;
var
  res,tmp:int64;
begin
  if b=0 then exit(1);
  tmp:=pow(a,b div 2);
  res:=sqr(tmp) mod module;
  if odd(b) then res:=res*a mod module;
  pow:=res;
end;

function nCr(n,r:int64):int64;
var
  res:int64;
begin
  res:=f[n]*fi[r] mod module*fi[n-r] mod module;
  nCr:=res;
end;

procedure prep;
var
  i:longint;
begin
  fillchar(f,sizeof(f),0);
  fillchar(fi,sizeof(fi),0);
  f[0]:=1;
  fi[0]:=1;
  for i:=1 to 200000 do
    begin
      f[i]:=f[i-1]*int64(i) mod module;
      fi[i]:=pow(f[i],module-2);
    end;
end;

procedure solve;
var
  i,j:longint;
  tmp:int64;
begin
  fillchar(p,sizeof(p),0);
  for i:=1 to n do
    begin
      p[i]:=nCr(a[i].row+a[i].col-2,a[i].row-1);
      for j:=1 to i-1 do
        if a[i].col>=a[j].col then
          begin
            tmp:=nCr(a[i].row+a[i].col-a[j].row-a[j].col,a[i].row-a[j].row)*p[j] mod module;
            p[i]:=(p[i]-tmp+module) mod module;
          end;
    end;
  ans:=nCr(h+w-2,h-1);
  for i:=1 to n do
    begin
      tmp:=nCr(h+w-a[i].row-a[i].col,h-a[i].row)*p[i] mod module;
      ans:=(ans-tmp+module) mod module;
    end;
end;

begin
  enter;
  sort;
  prep;
  solve;
  writeln(ans);
end.
