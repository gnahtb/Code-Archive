{$MODE OBJFPC}
uses
  gvector;
const
  maxN=trunc(1E5)+5;
type
  vectorli=specialize TVector<longint>;
  cmp=function(x,y:longint):boolean;
  pqli=class
  public
    data:array[0..1000000] of longint;
    size:longint;
    constructor create;
    procedure moveUp(child:longint;c:cmp); inline;
    procedure moveDown(parent:longint;c:cmp); inline;
    procedure push(val:longint;c:cmp); inline;
    procedure pop(c:cmp); inline;
    function top:longint; inline;
    function isEmpty:boolean; inline;
  end;
var
  n,m:longint;
  a:array[0..maxN] of vectorli;
  d,p,ans:array[0..maxN] of longint;
  pq:pqli;

constructor pqli.create;
begin
  fillchar(data,sizeof(data),0);
  size:=0;
end;

procedure pqli.moveUp(child:longint;c:cmp);
var
  parent,tmp:longint;
begin
  tmp:=data[child];
  while child>1 do
    begin
      parent:=child >> 1;
      if c(data[parent],tmp) then
        begin
          data[child]:=data[parent]; p[data[parent]]:=child;
          child:=parent;
        end
      else break;
    end;
  data[child]:=tmp; p[tmp]:=child;
end;

procedure pqli.moveDown(parent:longint;c:cmp);
var
  child,tmp:longint;
begin
  tmp:=data[parent];
  while true do
    begin
      child:=parent << 1;
      if (child<size) and c(data[child],data[child+1]) then inc(child);
      if (child>size) or not c(tmp,data[child]) then break;
      data[parent]:=data[child]; p[data[child]]:=parent;
      parent:=child;
    end;
  data[parent]:=tmp; p[tmp]:=parent;
end;

procedure pqli.push(val:longint;c:cmp);
begin
  inc(size); data[size]:=val; p[val]:=size;
  moveUp(size,c);
end;

procedure pqli.pop(c:cmp);
begin
  data[1]:=data[size]; data[size]:=0; dec(size); p[data[1]]:=1;
  moveDown(1,c);
end;

function pqli.top:longint; begin top:=data[1]; end;
function pqli.isEmpty:boolean; begin isEmpty:=size<=0; end;

function c(x,y:longint):boolean;
begin
  c:=d[x]>d[y];
  if d[x]=d[y] then c:=x<y;
end;

procedure enter;
var
  i,u,v:longint;
begin
  readln(n,m);
  for i:=1 to n do a[i]:=vectorli.create;
  fillchar(d,sizeof(d),0);
  for i:=1 to m do
    begin
      readln(u,v);
      a[v].pushback(u);
      inc(d[u]);
    end;
end;

procedure solve;
var
  i,u,x:longint;
begin
  pq:=pqli.create;
  for i:=1 to n do pq.push(i,@c);
  fillchar(ans,sizeof(ans),0);
  x:=n;
  while not pq.isEmpty do
    begin
      u:=pq.top; pq.pop(@c);
      ans[u]:=x; dec(x);
      for i:=0 to a[u].size-1 do
        begin
          dec(d[a[u][i]]);
          pq.moveUp(p[a[u][i]],@c);
        end;
    end;
  for i:=1 to n do write(ans[i],' ');
end;

begin
  enter;
  solve;
end.
