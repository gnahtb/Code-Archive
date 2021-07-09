const
  maxN=trunc(1E5)+5;
var
  n:int64;

function isPrime(x:longint):boolean;
var
  i:longint;
begin
  if x<2 then exit(false);
  for i:=2 to trunc(sqrt(x)) do
    if x mod i=0 then exit(false);
  isPrime:=true;
end;

function pow(a,b,c:int64):int64;
var
  res:int64;
begin
  if b=0 then exit(1);
  res:=sqr(pow(a,b >> 1,c)) mod c;
  if b and 1=1 then res:=res*a mod c;
  pow:=res;
end;

procedure solve;
var
  i:longint;
  x,y:int64;
begin
  writeln(1);
  for i:=2 to n-1 do
    begin
      y:=pow(int64(i-1),int64(n-2),int64(n));
      x:=int64(i)*y mod int64(n);
      writeln(x);
    end;
  writeln(n);
end;

begin
  readln(n);
  if n=1 then
    begin
      writeln('YES');
      writeln(1);
      halt;
    end;
  if n=4 then
    begin
      writeln('YES');
      writeln(1); writeln(3); writeln(2); writeln(4);
      halt;
    end;
  if not isPrime(n) then
    begin
      writeln('NO');
      exit;
    end;
  writeln('YES');
  solve;
end.
