uses math;
const
  maxN=trunc(3e5)+5;
  maxM=trunc(3e5)+5;
type
  TEdge=record
    u,v:longint;
  end;
var
  e:array[0..maxM] of TEdge;
  edgeFree:array[0..maxM] of boolean;
  bridge:array[0..maxM] of boolean;
  head,number,low:array[0..maxN] of longint;
  adj,ind:array[0..maxM*2] of longint;
  nodeFree:array[0..maxN] of boolean;
  n,m,time,ans:longint;

procedure enter;
var
  i:longint;
begin
  fillchar(head,sizeof(head),0);
  readln(n,m);
  for i:=1 to m do
    with e[i] do
      begin
        readln(u,v);
        inc(head[u]);
        inc(head[v]);
      end;
end;

procedure build;
var
  i:longint;
begin
  for i:=2 to n do head[i]:=head[i-1]+head[i];
  for i:=1 to m do
    with e[i] do
      begin
        adj[head[u]]:=v;
        ind[head[u]]:=i;
        adj[head[v]]:=u;
        ind[head[v]]:=i;
        dec(head[u]);
        dec(head[v]);
      end;
  head[n+1]:=m*2;
end;

procedure DFS(u,p:longint);
var
  i,child:longint;
begin
  inc(time);
  number[u]:=time;
  low[u]:=time;
  child:=0;
  for i:=head[u]+1 to head[u+1] do
    if edgeFree[ind[i]] then
      begin
        edgeFree[ind[i]]:=false;
        if number[adj[i]]>0 then
          low[u]:=min(low[u],number[adj[i]])
        else
          begin
            DFS(adj[i],u);
            inc(child);
            low[u]:=min(low[u],low[adj[i]]);
            if low[adj[i]]>=number[adj[i]] then
              bridge[ind[i]]:=true;
          end;
      end;
end;

procedure findBridges;
var
  i:longint;
begin
  fillchar(bridge,sizeof(bridge),false);
  fillchar(number,sizeof(number),0);
  fillchar(edgeFree,sizeof(edgeFree),true);
  for i:=1 to n do
    if number[i]<=0 then
      begin
        time:=0;
        DFS(i,i);
      end;
end;

procedure LP(var tmp,x:longint;u:longint;store:boolean);
var
  queue,d:array[0..maxN] of longint;
  first,last,i:longint;
begin
  first:=1;
  last:=1;
  queue[1]:=u;
  d[1]:=0;
  x:=u;
  tmp:=0;
  nodeFree[u]:=false;
  repeat
    u:=queue[first];
    for i:=head[u]+1 to head[u+1] do
      if nodeFree[adj[i]] then
        begin
          inc(last);
          queue[last]:=adj[i];
          nodeFree[adj[i]]:=false;
          d[last]:=d[first];
          if bridge[ind[i]] then
            begin
              inc(d[last]);
              if tmp<d[last] then
                begin
                  x:=adj[i];
                  tmp:=d[last];
                end;
            end;
        end;
    inc(first);
  until first>last;
  if not store then
    for i:=1 to last do nodeFree[queue[i]]:=true;
end;

procedure solve;
var
  i,x,tmp:longint;
begin
  ans:=0;
  fillchar(nodeFree,sizeof(nodeFree),true);
  for i:=1 to n do
    if nodeFree[i] then
      begin
        tmp:=0;
        LP(tmp,x,i,false);
        LP(tmp,x,x,true);
        ans:=max(ans,tmp);
      end;
end;

begin
  enter;
  build;
  findBridges;
  solve;
  writeln(ans);
end.
