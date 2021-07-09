uses
  math;
const
  limit=trunc(1E6)+5;
var
  a,f:array[0..limit] of longint;
  ans:longint;

procedure enter;
var
  i,n,t:longint;
begin
  fillchar(a,sizeof(a),0);
  readln(n);
  for i:=1 to n do
    begin
      read(t);
      inc(a[t]);
    end;
end;

procedure solve;
var
  i,j:longint;
begin
  fillchar(f,sizeof(f),0);
  ans:=0;
  for i:=1 to 1000000 do
    if a[i]>0 then
      begin
        f[i]+=a[i];
        ans:=max(ans,f[i]);
        for j:=2 to 1000000 div i do
          f[i*j]:=max(f[i*j],f[i]);
      end;
end;

begin
  enter;
  solve;
  writeln(ans);
end.
