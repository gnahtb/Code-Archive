uses
  math;
var
  n,s,k,t:longint;
  a,b:array[0..105] of longint;
  f:array[0..1,0..105,0..10005] of longint;

procedure enter;
var
  i:longint;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  readln(n);
  s:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      s:=s+a[i];
    end;
  for i:=1 to n do read(b[i]);
end;

procedure swap(var x,y:longint);
var
  t:longint;
begin
  t:=x; x:=y; y:=t;
end;

procedure sort;
var
  i,j:longint;
begin
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if b[i]<b[j] then
        begin
          swap(a[i],a[j]);
          swap(b[i],b[j]);
        end;
end;

procedure solve;
var
  i,j,l:longint;
begin
  l:=0;
  for k:=1 to n do
    begin
      l:=l+b[k];
      if l>=s then break;
    end;
  for i:=0 to 1 do
    for j:=0 to 105 do
      for l:=0 to 10005 do f[i,j,l]:=-1;
  f[0,0,0]:=0; f[1,0,0]:=0;
  for i:=1 to n do
    for j:=1 to k do
      for l:=0 to 10000 do
        begin
          f[i and 1,j,l]:=f[(i-1) and 1,j,l];
          if (l>=b[i]) and (f[(i-1) and 1,j-1,l-b[i]]<>-1) then
            f[i and 1,j,l]:=max(f[i and 1,j,l],f[(i-1) and 1,j-1,l-b[i]]+a[i]);
        end;
  t:=0;
  for l:=s to 10000 do t:=max(t,f[n and 1,k,l]);
  t:=s-t;
end;

begin
  enter;
  sort;
  solve;
  writeln(k,' ',t);
end.
