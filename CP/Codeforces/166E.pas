{$MODE OBJFPC}
type
  TMatrix=array[1..4,1..4] of int64;
const
  module=trunc(1E9)+7;
  base:TMatrix=((0,1,1,1),(1,0,1,1),(1,1,0,1),(1,1,1,0));
var
  n:longint;
  ans:TMatrix;

operator *(a,b:TMatrix) c:TMatrix;
var
  i,j,k:longint;
begin
  fillchar(c,sizeof(c),0);
  for i:=1 to 4 do
    for j:=1 to 4 do
      for k:=1 to 4 do
        c[i,j]:=(c[i,j]+a[i,k]*b[k,j] mod module) mod module;
end;

function pow(a:TMatrix;b:longint):TMatrix;
var
  t:TMatrix;
begin
  if b=1 then exit(a);
  t:=pow(a,b div 2);
  t:=t*t;
  if odd(b) then t:=t*a;
  pow:=t;
end;

begin
  readln(n);
  ans:=pow(base,n);
  writeln(ans[4,4]);
end.
