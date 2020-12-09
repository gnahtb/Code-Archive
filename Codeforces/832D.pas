{$MODE OBJFPC}
uses
  math,gvector;
const
  maxN=trunc(1E5)+5;
type
  vectorli=specialize TVector<longint>;
var
  n,q,a,b,c:longint;
  adj:array[0..maxN] of vectorli;
  d:array[0..maxN] of longint;
  p:array[0..maxN,0..20] of longint;

procedure swap(var x,y:longint);
var
  t:longint;
begin
  t:=x; x:=y; y:=t;
end;

procedure enter;
var
  i,p:longint;
begin
  for i:=1 to n do adj[i]:=vectorli.create;
  for i:=2 to n do
    begin
      read(p);
      adj[i].pushback(p);
      adj[p].pushback(i);
    end;
end;

procedure DFS(u:longint);
var
  i,v:longint;
begin
  for i:=0 to adj[u].size-1 do
    begin
      v:=adj[u][i];
      if v<>p[u,0] then
        begin
          p[v,0]:=u;
          d[v]:=d[u]+1;
          DFS(v);
        end;
    end;
end;

procedure buildLCA;
var
  i,j:longint;
begin
  fillchar(d,sizeof(d),0);
  fillchar(p,sizeof(p),0);
  DFS(1);
  for j:=1 to 20 do
    for i:=1 to n do p[i,j]:=p[p[i,j-1],j-1];
end;

function getLCA(u,v:longint):longint;
var
  delta,i:longint;
begin
  if d[u]<d[v] then swap(u,v);
  delta:=d[u]-d[v];
  for i:=20 downto 0 do
    if (delta >> i) and 1=1 then u:=p[u,i];
  if u=v then exit(u);
  for i:=20 downto 0 do
    if p[u,i]<>p[v,i] then
      begin
        u:=p[u,i];
        v:=p[v,i];
      end;
  getLCA:=p[u,0];
end;

procedure solve;
var
  x,y,z,cur,ans:longint;
begin
  x:=getLCA(a,b);
  y:=getLCA(b,c);
  z:=getLCA(c,a);
  if (d[x]>=d[y]) and (d[x]>=d[z]) then cur:=x;
  if (d[y]>=d[x]) and (d[y]>=d[z]) then cur:=y;
  if (d[z]>=d[x]) and (d[z]>=d[y]) then cur:=z;
  ans:=0;
  x:=getLCA(a,cur);
  ans:=max(ans,d[a]+d[cur]-(d[x] << 1));
  x:=getLCA(b,cur);
  ans:=max(ans,d[b]+d[cur]-(d[x] << 1));
  x:=getLCA(c,cur);
  ans:=max(ans,d[c]+d[cur]-(d[x] << 1));
  writeln(ans+1);
end;

begin
  readln(n,q);
  enter;
  buildLCA;
  for q:=q downto 1 do
    begin
      readln(a,b,c);
      solve;
    end;
end.
