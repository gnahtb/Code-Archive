uses
  math;
var
  a,b,c:array[0..105] of longint;
  f:array[0..105,-20005..20005] of longint;
  n,k,i,j:longint;
begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do c[i]:=a[i]-k*b[i];
  for i:=0 to 105 do
    for j:=-20005 to 20005 do f[i,j]:=-1;
  f[0,0]:=0;
  for i:=1 to n do
    for j:=-10000 to 10000 do
      begin
        f[i,j]:=f[i-1,j];
        if f[i-1,j-c[i]]>=0 then
          f[i,j]:=max(f[i,j],f[i-1,j-c[i]]+a[i]);
      end;
  if f[n,0]>0 then write(f[n,0]) else write(-1);
end.
