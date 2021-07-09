uses
  math;
const
  module=trunc(1e8);
var
  ans,i,j,k,n1,n2,k1,k2:longint;
  f:array[0..105,0..105,0..1] of int64;
begin
  readln(n1,n2,k1,k2);
  f[0,0,0]:=1;
  f[0,0,1]:=1;
  for i:=0 to n1 do
    for j:=0 to n2 do
      begin
        for k:=1 to min(i,k1) do f[i,j,0]:=(f[i,j,0]+f[i-k,j,1]) mod module;
        for k:=1 to min(j,k2) do f[i,j,1]:=(f[i,j,1]+f[i,j-k,0]) mod module;
      end;
  ans:=(f[n1,n2,0]+f[n1,n2,1]) mod module;
  writeln(ans);
end.
