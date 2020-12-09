{$MODE OBJFPC}
uses
  gvector;
const
  module=trunc(1E9)+7;
type
  vectorint=specialize TVector<int64>;
var
  x,y,ans:int64;
  f:array[0..100005] of int64;
  d:vectorint;

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

procedure sort(var a:vectorint);
var
  i,j:longint;
  t:int64;
begin
  for i:=0 to a.size-2 do
    for j:=i+1 to a.size-1 do
      if a[i]<a[j] then
        begin
          t:=a[i]; a[i]:=a[j]; a[j]:=t;
        end;
end;

procedure solve;
var
  i,j:longint;
begin
  y:=y div x;
  ans:=pow(2,y-1);
  d:=vectorint.create;
  for i:=1 to trunc(sqrt(y)) do
    if y mod i=0 then
      begin
        if i>1 then d.pushback(i);
        if y div int64(i)<>i then d.pushback(y div int64(i));
      end;
  sort(d);
  for i:=0 to d.size-1 do
    begin
      f[i]:=pow(2,y div d[i]-1);
      for j:=0 to i-1 do
        if d[j] mod d[i]=0 then f[i]:=(f[i]-f[j]+module) mod module;
      ans:=(ans-f[i]+module) mod module;
    end;
end;

begin
  readln(x,y);
  if y mod x<>0 then
    begin
      write(0);
      halt;
    end;
  solve;
  writeln(ans);
end.
