uses
  math;
const
  lim=trunc(2E6);
  inf=trunc(1E18);
var
  x,y,ans:int64;
  c,s:array[0..lim] of int64;

procedure enter;
var
  a,n:int64;
begin
  fillchar(c,sizeof(c),0);
  fillchar(s,sizeof(s),0);
  readln(n,x,y);
  while n>0 do
    begin
      read(a);
      inc(c[a]);
      s[a]:=s[a]+a;
      dec(n);
    end;
end;

procedure solve;
var
  i,j,k:longint;
  p,cur:int64;
begin
  for i:=1 to trunc(2E6) do
    begin
      c[i]:=c[i-1]+c[i];
      s[i]:=s[i-1]+s[i];
    end;
  ans:=inf;
  for i:=2 to trunc(1E6) do
    begin
      cur:=0; j:=0;
      while j<=trunc(1E6) do
        begin
          k:=j+i;
          p:=max(int64(j),(int64(k)*y-x) div y);
          cur:=cur+(c[p]-c[j])*x+(int64(k)*(c[k]-c[p])-(s[k]-s[p]))*y;
          j:=k;
        end;
      ans:=min(ans,cur);
    end;
end;

begin
  enter;
  solve;
  writeln(ans);
end.
