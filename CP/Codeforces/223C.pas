{$MODE OBJFPC}
const
  modulo=trunc(1E9)+7;
var
  n,k:longint;
  a,b,fi,g:array[0..2005] of int64;

procedure enter;
var
  i:longint;
begin
  fillchar(a,sizeof(a),0);
  readln(n,k);
  for i:=1 to n do read(a[i]);
end;

function pow(a,b:int64):int64;
var
  t:int64;
begin
  if b=0 then exit(1);
  t:=sqr(pow(a,b >> 1)) mod modulo;
  if b and 1=1 then t:=t*a mod modulo;
  pow:=t;
end;

procedure prep;
var
  i:longint;
  f:int64;
begin
  fillchar(fi,sizeof(fi),0);
  fillchar(g,sizeof(g),0);
  f:=1; fi[0]:=1;
  g[0]:=1;
  for i:=1 to 2000 do
    begin
      f:=f*int64(i) mod modulo;
      fi[i]:=pow(f,modulo-2);
      g[i]:=g[i-1]*int64(k+i-1) mod modulo;
    end;
end;

procedure solve;
var
  i,j:longint;
  t:int64;
begin
  fillchar(b,sizeof(b),0);
  if k=0 then b:=a
  else
    for i:=1 to n do
      for j:=1 to i do
        begin
          t:=g[i-j]*fi[i-j] mod modulo*a[j] mod modulo;
          b[i]:=(b[i]+t) mod modulo;
        end;
  for i:=1 to n do write(b[i],' ');
end;

begin
  enter;
  prep;
  solve;
end.
