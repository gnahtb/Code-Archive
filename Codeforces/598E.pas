uses
  math;
const
  inf=trunc(2E9);
var
  f:array[0..35,0..35,0..55] of longint;

procedure prep;
var
  n,m,k,p,d,t,cost,remain:longint;
begin
  fillchar(f,sizeof(f),0);
  for n:=0 to 35 do
    for m:=0 to 35 do
      for k:=1 to 55 do f[n,m,k]:=inf;
  f[0,0,0]:=0;
  for n:=1 to 30 do
    for m:=1 to 30 do
      for k:=1 to min(n*m,50) do
        begin
          if k=n*m then
            begin
              f[n,m,k]:=0;
              continue;
            end;
          for p:=1 to k do
            for d:=1 to p do
              if (p mod d=0) and (n>=d) and (m>=p div d) then
                begin
                  remain:=k-p;
                  t:=p div d;
                  cost:=sqr(m);
                  if t<>m then cost:=cost+sqr(d);
                  f[n,m,k]:=min(f[n,m,k],cost+min(f[n-d,m,remain],f[d,m-t,remain]));
                  cost:=sqr(n);
                  if d<>n then cost:=cost+sqr(t);
                  f[n,m,k]:=min(f[n,m,k],cost+min(f[n,m-t,remain],f[n-d,t,remain]));
                end;
        end;
end;

procedure solve;
var 
  t,n,m,k:longint;
begin
  readln(t);
  for t:=t downto 1 do
    begin
      readln(n,m,k);
      writeln(f[n,m,k]);
    end;
end;

begin
  prep;
  solve;
end.
