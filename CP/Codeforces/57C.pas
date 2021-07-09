const
  modulo=trunc(1E9)+7;
var
  n:int64;
  f:array[0..200005] of int64;

function pow(a,b:int64):int64;
var
  res:int64;
begin
  if b=0 then exit(1);
  res:=sqr(pow(a,b >> 1)) mod modulo;
  if b and 1=1 then res:=res*a mod modulo;
  pow:=res;
end;

procedure solve;
var
  i:longint;
  tmp:int64;
begin
  fillchar(f,sizeof(f),0);
  f[0]:=1;
  for i:=1 to (n << 1) do f[i]:=f[i-1]*int64(i) mod modulo;
  tmp:=sqr(pow(f[n],modulo-2)) mod modulo;
  writeln((f[n << 1]*tmp mod modulo-n+modulo) mod modulo);
end;

begin
  readln(n);
  solve;
end.
