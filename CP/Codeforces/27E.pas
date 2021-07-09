uses
  math;
const
  inf=trunc(1E18)+5;
  p:array[1..10] of int64=(2,3,5,7,11,13,17,19,23,29);
var
  n,i,j,k,l:longint;
  x:int64;
  f:array[0..1005,0..15] of int64;
begin
  for j:=0 to 10 do f[1,j]:=1;
  for i:=2 to 1005 do
    for j:=0 to 15 do f[i,j]:=inf;
  readln(n);
  for i:=2 to n do
    for j:=1 to 10 do
      begin
        f[i,j]:=min(f[i,j],f[i,j-1]);
        l:=trunc(logn(p[j],inf));
        x:=1;
        for k:=1 to l do
          begin
            if (k>1) and (i mod k=0) and (f[i div k,j-1]<inf) and (f[i div k,j-1]<inf div x) then
              f[i,j]:=min(f[i,j],f[i div k,j-1]*x);
            x*=p[j];
          end;
      end;
  writeln(f[n,10]);
end.
