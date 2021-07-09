{$MODE OBJFPC}
uses
  gstack,
  math;
const
  maxN=1005;
type
  TEdge=record u,v:longint; end;
  TDisjointSet=class
  public
    root,depth:array[0..maxN] of longint;
    constructor create;
    function getRoot(u:longint):longint; inline;
    procedure makeSet(root1,root2:longint); inline;
  end;
  stackli=specialize TStack<longint>;
var
  n,t:longint;
  e:array[0..maxN] of TEdge;
  used:array[0..maxN] of boolean;
  dsu:TDisjointSet;
  stack:stackli;

constructor TDisjointSet.create;
begin
  fillchar(root,sizeof(root),0);
  fillchar(depth,sizeof(depth),0);
end;

function TDisjointSet.getRoot(u:longint):longint;
begin
  while root[u]>0 do u:=root[u];
  getRoot:=u;
end;

procedure TDisjointSet.makeSet(root1,root2:longint);
begin
  if depth[root1]<depth[root2] then
    begin
      root[root1]:=root2;
      depth[root2]:=max(depth[root1]+1,depth[root2]);
    end
  else
    begin
      root[root2]:=root1;
      depth[root1]:=max(depth[root2]+1,depth[root1]);
    end;
end;

procedure enter;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n-1 do
    with e[i] do readln(u,v);
end;

procedure solve;
var
  i,root1,root2:longint;
begin
  dsu:=TDisjointSet.create;
  fillchar(used,sizeof(used),false);
  t:=n-1;
  for i:=1 to n-1 do
    with e[i] do
      begin
        root1:=dsu.getRoot(u);
        root2:=dsu.getRoot(v);
        if root1<>root2 then
          begin
            dsu.makeSet(root1,root2);
            used[i]:=true;
            dec(t);
          end;        
      end;

  writeln(t);
  stack:=stackli.create;
  for i:=1 to n do
    if dsu.getRoot(i)=i then stack.push(i);
  for i:=1 to n-1 do
    if not used[i] then
      with e[i] do
        begin
          write(u,' ',v,' ',stack.top,' ');
          stack.pop;
          writeln(stack.top);
        end;
end;

begin
  enter;
  solve;
end.
