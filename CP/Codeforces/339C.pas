{$MODE OBJFPC}
uses
  gstack;
type
  TIntStack=specialize TStack<longint>;
var
  p:array[0..15] of boolean;
  f:array[0..1005,0..15,0..15] of boolean;
  m,s:longint;

procedure enter;
var
  i:longint;
  c:char;
begin
  fillchar(p,sizeof(p),false);
  for i:=1 to 10 do
    begin
      read(c);
      if c='1' then p[i]:=true;
    end;
  readln(m);
end;

procedure solve;
var
  i,j,k,l:longint;
begin
  fillchar(f,sizeof(f),false);
  for j:=1 to 10 do
    if p[j] then f[1,j,j]:=true;
  for i:=2 to m do
    for j:=1 to 10 do
      for k:=j+1 to 10 do
        if p[k] then
          for l:=1 to 10 do
            if p[l] and (l<>k) and f[i-1,k-j,l] then
              begin
                f[i,j,k]:=true;
                break;
              end;
  s:=-1;
  for j:=1 to 10 do
    for k:=1 to 10 do
      if f[m,j,k] then
        begin
          s:=j;
          break;
        end;
end;

function check(i,j,k:longint):boolean;
var
  l:longint;
begin
  for l:=1 to 10 do
    if (l<>k) and f[i-1,k-j,l] then exit(true);
  check:=false;
end;

procedure trace;
var
  ans:TIntStack;
  i,j,k:longint;
  flag:boolean;
begin
  ans:=TIntStack.create;
  ans.push(11);
  for i:=m downto 2 do
    for k:=1 to 10 do
      if f[i,s,k] and (k<>ans.top) then
        begin
          flag:=false;
          for j:=1 to 10 do
            if (j<>k) and f[i-1,k-s,j] then flag:=true;
          if flag then
            begin
              ans.push(k);
              s:=k-s;
              break;
            end;
        end;
  write(s,' ');
  while not ans.isEmpty do
    begin
      if ans.top<11 then write(ans.top,' ');
      ans.pop;
    end;
end;

begin
  enter;
  solve;
  if s>0 then
    begin
      writeln('YES');
      trace;
    end
  else writeln('NO');
end.
