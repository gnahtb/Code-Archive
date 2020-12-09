uses
  math;
const
  limit=trunc(2E6);
var
  n,k,x,ans:longint;
  cnt:array[0..limit] of longint;

procedure enter;
var
  i,a:longint;
begin
  fillchar(cnt,sizeof(cnt),0);
  readln(n,k);
  x:=maxlongint;
  for i:=1 to n do
    begin
      read(a);
      inc(cnt[a]);
      x:=min(x,a);
    end;
end;

procedure solve;
var
  i,j,l,r,tmp:longint;
begin
  for i:=1 to limit do cnt[i]:=cnt[i-1]+cnt[i];
  ans:=1;
  for i:=x downto 1 do
    if x mod i<=k then
      begin
        tmp:=0;
        for j:=1 to trunc(1E6) div i do
          begin
            l:=i*j;
            r:=i*j+k;
            tmp:=tmp+cnt[r]-cnt[l-1];
          end;
        if tmp>=n then
          begin
            ans:=i;
            break;
          end;
      end;
end;

begin
  enter;
  solve;
  writeln(ans);
end.
