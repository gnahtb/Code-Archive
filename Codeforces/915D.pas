{$MODE OBJFPC}
uses
  gstack,gvector,math;
const
  maxN=505;
type
  stackli=specialize TStack<longint>;
  vectorli=specialize TVector<longint>;
var
  n,time,cnt,g:longint;
  a:array[0..maxN] of vectorli;
  s:stackli;
  num,low,id,p:array[0..maxN] of longint;
  cur:array[0..maxN] of boolean;

procedure enter;
var
  i,m,u,v:longint;
begin
  readln(n,m);
  for i:=1 to n do a[i]:=vectorli.create;
  for i:=1 to m do
    begin
      readln(u,v);
      a[u].pushback(v);
    end;
end;

procedure findSCC(u:longint);
var
  i,v:longint;
begin
  inc(time); num[u]:=time; low[u]:=maxlongint;
  s.push(u);
  for i:=0 to a[u].size-1 do
    begin
      v:=a[u][i];
      if num[v]=0 then
        begin
          findSCC(v);
          low[u]:=min(low[u],low[v]);
        end
      else low[u]:=min(low[u],num[v]);
    end;
  if low[u]>=num[u] then
    begin
      inc(cnt);
      repeat
        v:=s.top; s.pop; id[v]:=cnt;
        num[v]:=maxlongint; low[v]:=maxlongint;
      until u=v;
    end;
end;

procedure prep;
var
  i:longint;
begin
  fillchar(num,sizeof(num),0);
  fillchar(low,sizeof(low),0);
  fillchar(id,sizeof(id),0);
  s:=stackli.create;
  cnt:=0;
  for i:=1 to n do
    if num[i]=0 then findSCC(i);
end;

procedure findReverseEdges(u:longint);
var
  i,v:longint;
begin
  num[u]:=1; cur[u]:=true;
  for i:=0 to a[u].size-1 do
    begin
      v:=a[u][i];
      if id[v]<>id[u] then continue;
      if num[v]=1 then
        begin
          if cur[v] then inc(g);
        end
      else findReverseEdges(v);
    end;
  cur[u]:=false;
end;

procedure solve;
var
  i,tmp:longint;
begin
  fillchar(p,sizeof(p),0);
  for i:=1 to n do
    begin
      fillchar(num,sizeof(num),0);
      fillchar(cur,sizeof(cur),false);
      g:=0;
      findReverseEdges(i);
      if p[id[i]]=0 then p[id[i]]:=g else p[id[i]]:=min(p[id[i]],g);
    end;
  tmp:=0;
  for i:=1 to cnt do tmp:=tmp+p[i];
  if tmp>1 then writeln('NO') else writeln('YES');
end;

begin
  enter;
  prep;
  solve;
end.
