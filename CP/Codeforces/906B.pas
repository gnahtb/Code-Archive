var
  n,m,i,j,c:longint;
  a:array[0..1,0..100005] of longint;
  p:array[0..100005] of longint;

procedure swap(var x,y:longint);
var
  t:longint;
begin
  t:=x; x:=y; y:=t;
end;

function getIndex(id:longint):longint;
begin
  if id<1 then id:=id+m;
  if id>m then id:=id-m;
  getIndex:=id;
end;

procedure prep;
var
  tmp:array[0..100005] of longint;
begin
  fillchar(a,sizeof(a),0);
  fillchar(tmp,sizeof(tmp),0);
  for i:=1 to m do
    begin
      a[0,i]:=i+m;
      a[1,i]:=i;
    end;

  for i:=1 to m do if i and 1=0 then swap(a[0,i],a[1,i]);
  for i:=1 to m do tmp[i]:=a[0,getIndex(i+2)];
  for i:=1 to m do a[0,i]:=tmp[i];

  fillchar(p,sizeof(p),0);
  c:=0;
  for i:=m downto 1 do
    if i and 1=1 then begin inc(c); p[c]:=i; end;
  for i:=m downto 1 do
    if i and 1=0 then begin inc(c); p[c]:=i; end;
  if n=3 then for i:=2 to m do swap(p[i],p[i-1]);
end;

procedure solve;
begin
  for i:=1 to (n >> 1)-1 do
    begin
      for j:=1 to m do write(a[1,j]+(i-1)*m*2,' ');
      writeln;
      for j:=1 to m do write(a[0,j]+(i-1)*m*2,' ');
      writeln;
    end;
  if n and 1=1 then
    begin
      for i:=1 to m do write(p[i]+(n-1)*m,' ');
      writeln;
    end;
  if n>1 then
    begin
      for j:=1 to m do write(a[1,j]+(((n >> 1) << 1)-2)*m,' ');
      writeln;
      for j:=1 to m do write(a[0,j]+(((n >> 1) << 1)-2)*m,' ');
    end;
end;

begin
  readln(n,m);
  if m=1 then
    begin
      if n=1 then begin writeln('YES'); writeln(1); end
      else if n in [2,3] then begin writeln('NO'); end
      else
        begin
          m:=n; prep;
          writeln('YES');
          for i:=1 to n do writeln(p[i]);
        end;
      halt;
    end;
  if m=2 then
    begin
      if n<4 then writeln('NO')
      else
        begin
          writeln('YES');
          fillchar(a,sizeof(a),0);
          c:=0;
          for i:=1 to n << 1 do
            if i mod 4=3 then begin inc(c); a[0,c]:=i; a[1,c]:=i+1; end;
          for i:=1 to c do
            if i and 1=1 then swap(a[0,i],a[1,i]);
          for i:=2 to c do swap(a[1,1],a[1,i]);
          for i:=1 to c do writeln(a[0,i],' ',a[1,i]);
          c:=0;
          for i:=1 to n << 1 do
            if i mod 4=1 then begin inc(c); a[0,c]:=i; a[1,c]:=i+1; end;
          for i:=2 to c do swap(a[1,1],a[1,i]);
          for i:=1 to c do writeln(a[0,i],' ',a[1,i]);
        end;
      halt;
    end;
  if m=3 then
    begin
      if n<3 then writeln('NO')
      else
        begin
          writeln('YES');
          if n mod 3=1 then
            begin
              for i:=1 to n div 3-1 do
                begin
                  writeln(6+(i-1)*9,' ',1+(i-1)*9,' ',8+(i-1)*9);
                  writeln(7+(i-1)*9,' ',5+(i-1)*9,' ',3+(i-1)*9);
                  writeln(2+(i-1)*9,' ',9+(i-1)*9,' ',4+(i-1)*9);
                end;
              writeln(n*m-1,' ',1+(n div 3-1)*9,' ',n*m);
              writeln(6+(n div 3-1)*9,' ',n*m-2,' ',8+(n div 3-1)*9);
              writeln(7+(n div 3-1)*9,' ',5+(n div 3-1)*9,' ',3+(n div 3-1)*9);
              writeln(2+(n div 3-1)*9,' ',9+(n div 3-1)*9,' ',4+(n div 3-1)*9);
            end;
          if n mod 3=2 then
            begin
              for i:=1 to n div 3-1 do
                begin
                  writeln(6+(i-1)*9,' ',1+(i-1)*9,' ',8+(i-1)*9);
                  writeln(7+(i-1)*9,' ',5+(i-1)*9,' ',3+(i-1)*9);
                  writeln(2+(i-1)*9,' ',9+(i-1)*9,' ',4+(i-1)*9);
                end;
              writeln(n*m-4,' ',1+(n div 3-1)*9,' ',n*m-3);
              writeln(6+(n div 3-1)*9,' ',n*m-5,' ',8+(n div 3-1)*9);
              writeln(7+(n div 3-1)*9,' ',5+(n div 3-1)*9,' ',3+(n div 3-1)*9);
              writeln(2+(n div 3-1)*9,' ',n*m-1,' ',4+(n div 3-1)*9);
              writeln(n*m-2,' ',9+(n div 3-1)*9,' ',n*m);
            end;
          if n mod 3=0 then
            for i:=1 to n div 3 do
              begin
                writeln(6+(i-1)*9,' ',1+(i-1)*9,' ',8+(i-1)*9);
                writeln(7+(i-1)*9,' ',5+(i-1)*9,' ',3+(i-1)*9);
                writeln(2+(i-1)*9,' ',9+(i-1)*9,' ',4+(i-1)*9);
              end;
        end;
      halt;
    end;
  writeln('YES');
  prep;
  solve;
end.
