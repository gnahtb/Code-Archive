{$MODE OBJFPC}
uses
  gvector;
const
  inf=trunc(1E6);
type
  vectorli=specialize TVector<longint>;
var
  a,b,h,w,r:longint;
  o:vectorli;
  f:array[0..2000000] of longint;

procedure enter;
var
  n,t:longint;
begin
  readln(a,b,h,w,n);
  o:=vectorli.create;
  for n:=n downto 1 do
    begin
      read(t);
      o.pushback(t);
    end;
end;

procedure sort(l,r:longint);
var
  i,j,x,y:longint;
begin
  i:=l; j:=r; x:=o[(l+r) >> 1];
  repeat
    while o[i]>x do inc(i);
    while x>o[j] do dec(j);
    if i<=j then
      begin
        y:=o[i]; o[i]:=o[j]; o[j]:=y;
        inc(i); dec(j);
      end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

function get_bit(state,position:longint):longint;
begin
  get_bit:=(state >> position) and 1;
end;

function mul(p,q:longint):longint;
begin
  if inf div q>=p then mul:=p*q else mul:=inf;
end;

procedure maximize(var x:longint;y:longint); begin if x<y then x:=y; end;

function check(x:longint):boolean;
var
  u,v:vectorli;
  s1,s2,i,mask,p1,p2,x1,y1,x2,y2,z1,z2:longint;
begin
  fillchar(f,sizeof(f),0);
  u:=vectorli.create;
  v:=vectorli.create;
  for i:=0 to ((x+1) >> 1)-1 do u.pushback(o[i]);
  for i:=((x+1) >> 1) to x-1 do v.pushback(o[i]);
  x1:=(a-1) div h+1; y1:=(b-1) div w+1; x2:=(a-1) div w+1; y2:=(b-1) div h+1;
  s1:=u.size; s2:=v.size;
  for mask:=0 to (1 << u.size)-1 do
    begin
      p1:=1; p2:=1;
      for i:=0 to u.size-1 do
        if get_bit(mask,i)=0 then p1:=mul(p1,u[i]) else p2:=mul(p2,u[i]);
      if ((h*p1>=a) and (w*p2>=b)) or ((h*p1>=b) and (w*p2>=a)) then exit(true);
      maximize(f[p1],p2);
    end;
  for i:=inf downto 1 do maximize(f[i],f[i+1]);
  for mask:=0 to (1 << v.size)-1 do
    begin
      p1:=1; p2:=1;
      for i:=0 to v.size-1 do
        if get_bit(mask,i)=0 then p1:=mul(p1,v[i]) else p2:=mul(p2,v[i]);
      z1:=(x1-1) div p1+1; z2:=mul(f[z1],p2);
      if z2>=y1 then exit(true);
      z1:=(x2-1) div p1+1; z2:=mul(f[z1],p2);
      if z2>=y2 then exit(true);
    end;
  check:=false;
end;

procedure solve;
var
  i:longint;
begin
  if ((h>=a) and (w>=b)) or ((h>=b) and (w>=a)) then
    begin
      r:=0;
      exit;
    end;
  sort(0,o.size-1);
  while o.size>34 do o.popback;
  for i:=1 to o.size do
    if check(i) then
      begin
        r:=i;
        exit;
      end;
  r:=-1;
end;

begin
  enter;
  solve;
  writeln(r);
end.
