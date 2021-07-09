const
  module=trunc(1e9)+7;
var
  n:longint;
  ans:int64;
  a,f:array[0..200005] of int64;

procedure enter;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
end;

procedure prep;
var
  i:longint;
begin
  fillchar(f,sizeof(f),0);
  f[0]:=1;
  for i:=1 to 200000 do f[i]:=f[i-1]*i mod module;
end;

function powDaC(a,b:int64):int64;
var
  res:int64;
begin
  if b=0 then exit(1);
  res:=sqr(powDaC(a,b div 2)) mod module;
  if odd(b) then res:=res*a mod module;
  powDaC:=res;
end;

function nCr(n,r:int64):int64;
var
  tmp1,tmp2,res:int64;
begin
  tmp1:=powDaC(f[n-r],module-2);
  tmp2:=powDaC(f[r],module-2);
  res:=f[n]*tmp1 mod module*tmp2 mod module;
  nCr:=res;
end;

procedure solve;
var
  tmp1,tmp2,x:int64;
  i:longint;
begin
  if n<2 then
    begin
      ans:=(a[1]+module) mod module;
      exit;
    end;
  if odd(n) then
    begin
      for i:=1 to n-1 do
        if odd(i) then a[i]:=(a[i]+a[i+1]+module) mod module
        else a[i]:=(a[i]-a[i+1]+module) mod module;
      dec(n);
    end;
  x:=0;
  tmp1:=0;
  tmp2:=0;
  for i:=1 to n do
    if odd(i) then
      tmp1:=(nCr(n div 2-1,x)*a[i] mod module+tmp1) mod module
    else
      begin
        tmp2:=(nCr(n div 2-1,x)*a[i] mod module+tmp2) mod module;
        inc(x);
      end;
  if n mod 4=0 then ans:=(tmp1-tmp2+module) mod module
  else ans:=(tmp1+tmp2) mod module;
end;

begin
  prep;
  enter;
  solve;
  writeln(ans);
end.
