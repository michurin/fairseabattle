Name:		fairseabattle
Version:	1.0
Release:	1%{?dist}
Summary:	Battleship type game you might have played before

Group:		Amusements/Games
License:	GPLv3
URL:		http://fairseabattle.googlecode.com/
Source0:	http://fairseabattle.googlecode.com/files/%{name}-%{version}.tar.gz
BuildRoot:	%(mktemp -ud %{_tmppath}/%{name}-%{version}-%{release}-XXXXXX)

BuildRequires:	qt-devel >= 4.4
BuildRequires:	libgcc >= 4.4
BuildRequires:	gcc-c++ >= 4.4
Requires:	qt >= 4.4
Requires:	qt-x11 >= 4.4

%description
Sink the computer's fleet!

%prep
%setup -q

%build
qmake-qt4
make

%install
rm -rf $RPM_BUILD_ROOT
# hackish
mkdir -p $RPM_BUILD_ROOT%{_bindir}
cp -f %{name} $RPM_BUILD_ROOT%{_bindir}
# /hackish

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)
%{_bindir}/%{name}
%doc README COPYING

%changelog
* Fri Jan 15 2010 Alexey Michurin <a.michurin at, gmail.com> 1.0-1
- Initial release
