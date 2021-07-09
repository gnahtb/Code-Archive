uses
  math;
const
  module=trunc(1E9)+7;
  lim=trunc(2E6)+5;
var
  d,f,pw2:array[0..lim] of int64;
  q,x,y,ans:int64;

function pow(a,b:int64):int64;
var
  res:int64;
begin
  if b=0 then exit(1);
  res:=sqr(pow(a,b div 2)) mod module;
  if odd(b) then res:=res*a mod module;
  pow:=res;
end;

function nCr(n,r:int64):int64;
var
  res,tmp1,tmp2:int64;
begin
  tmp1:=pow(f[n-r],module-2);
  tmp2:=pow(f[r],module-2);
  res:=f[n]*tmp1 mod module*tmp2 mod module;
  nCr:=res;
end;

procedure prep;
var
  i:longint;
begin
  fillchar(f,sizeof(f),0);
  fillchar(pw2,sizeof(pw2),0);
  f[0]:=1;
  pw2[0]:=1;
  for i:=1 to lim do
    begin
      f[i]:=f[i-1]*i mod module;
      pw2[i]:=pw2[i-1]*2 mod module;
    end;
end;

procedure sieve;
var
  i,j:longint;
begin
  fillchar(d,sizeof(d),0);
  for i:=2 to lim do d[i]:=i;
  for i:=2 to trunc(sqrt(lim)) do
    if d[i]=i then
      for j:=i to lim div i do
        d[i*j]:=min(d[i*j],i);
end;

procedure solve;
var
  c,t:int64;
begin
  ans:=1;
  while x>1 do
    begin
      c:=0;
      t:=d[x];
      while x mod t=0 do
        begin
          inc(c);
          x:=x div t;
        end;
      ans:=ans*nCr(c+y-1,c) mod module;
    end;
  ans:=ans*pw2[y-1] mod module;
end;

begin
  prep;
  sieve;
  readln(q);
  while q>0 do
    begin
      readln(x,y);
      solve;
      writeln(ans);
      dec(q);
    end;
end.
