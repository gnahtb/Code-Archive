const
  module=trunc(1E9)+7;
var
  n:longint;
  p,q,t,a:int64;
  flag:boolean;

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

begin
  read(n);
  flag:=false;
  p:=2;
  while n>0 do
    begin
      read(a);
      if not odd(a) then flag:=true;
      p:=pow(p,a);
      dec(n);
    end;
  p:=p*500000004 mod module;
  q:=p;
  if flag then p:=(p+1) mod module
  else p:=(p-1+module) mod module;
  p:=p*333333336 mod module;
  writeln(p,'/',q);
end.
