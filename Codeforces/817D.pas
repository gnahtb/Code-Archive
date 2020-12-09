{$MODE OBJFPC}
uses
  gstack;
const
  maxN=trunc(1e6)+5;
type
  TIntStack=specialize TStack<longint>;
  TList=array[0..maxN] of longint;
var
  a:array[1..maxN] of longint;
  lmax,rmax,lmin,rmin:TList;
  stack:TIntStack;
  n:longint;
  ans:int64;

procedure enter;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
end;

procedure buildLR(var left,right:TList);
var
  i:longint;
begin
  while not stack.isEmpty do stack.pop;
  for i:=1 to n do
    begin
      while not stack.isEmpty and (a[stack.top]<a[i]) do stack.pop;
      if not stack.isEmpty then left[i]:=stack.top
      else left[i]:=0;
      stack.push(i);
    end;
  while not stack.isEmpty do stack.pop;
  for i:=n downto 1 do
    begin
      while not stack.isEmpty and (a[stack.top]<=a[i]) do stack.pop;
      if not stack.isEmpty then right[i]:=stack.top
      else right[i]:=n+1;
      stack.push(i);
    end;
end;

function getLength(l,r,p:longint):int64;
begin
  getLength:=int64(p-l)*int64(r-p);
end;

procedure Solve;
var
  i:longint;
  t:int64;
begin
  stack:=TIntStack.create;
  buildLR(lmax,rmax);
  for i:=1 to n do a[i]:=-a[i];
  buildLR(lmin,rmin);
  ans:=0;
  for i:=1 to n do
    begin
      t:=getLength(lmax[i],rmax[i],i);
      ans:=ans-a[i]*t;
      t:=getLength(lmin[i],rmin[i],i);
      ans:=ans+a[i]*t;
    end;
end;

begin
  enter;
  solve;
  writeln(ans);
end.

