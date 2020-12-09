{$MODE OBJFPC}
type
  TMatrix=array[1..2,1..2] of int64;
const
  base:TMatrix=((0,1),(1,1));
var
  n,k,l,m,ans:int64;

operator *(a,b:TMatrix) c:TMatrix;
var
  i,j,k:longint;
begin
  fillchar(c,sizeof(c),0);
  for i:=1 to 2 do
    for j:=1 to 2 do
      for k:=1 to 2 do
        c[i,j]:=(c[i,j]+a[i,k]*b[k,j]) mod m;
end;

operator **(a:TMatrix;b:int64) c:TMatrix;
begin
  if b=1 then exit(a);
  c:=a**(b >> 1);
  c:=c*c;
  if b and 1=1 then c:=c*a;
end;

function pow2(b:int64):int64;
var
  res:int64;
begin
  if b=0 then exit(1);
  res:=pow2(b >> 1);
  res:=sqr(res) mod m;
  if b and 1=1 then res:=res*2 mod m;
  pow2:=res;
end;

function fibo(x:int64):int64;
const
  start:TMatrix=((2,3),(0,0));
var
  res:TMatrix;
begin
  if x=1 then exit(2);
  if x=2 then exit(3);
  res:=base**(x-2);
  res:=start*res;
  fibo:=res[1,2];
end;

procedure solve;
var
  i:longint;
  f,x:int64;
begin
  ans:=1 mod m;
  f:=fibo(n);
  x:=(pow2(n)-f+m) mod m;
  for i:=1 to l do
    begin
      if k and 1=1 then ans:=ans*x mod m
      else ans:=ans*f mod m;
      k:=k >> 1;
    end;
  if k<>0 then ans:=0;
end;

begin
  readln(n,k,l,m);
  solve;
  writeln(ans);
end.
