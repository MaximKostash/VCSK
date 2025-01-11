#!/bin/bash

INSTALL_CMAKE=false
INSTALL_PKG_CONFIG=false

if command -v cmake &> /dev/null; then
  echo "cmake у вас скачан."
else
  echo "cmake не скачан. Качаем."
  INSTALL_CMAKE=true
fi

if command -v pkg-config &> /dev/null; then
  echo "pkg-config у вас скачан."
else
  echo "pkg-config не скачан. Качаем."
  INSTALL_PKG_CONFIG=true
fi

if $INSTALL_CMAKE || $INSTALL_PKG_CONFIG; then
  echo "Установка необходимых пакетов может занять несколько минут."
  echo "Нажмите Enter, чтобы продолжить установку."
  read -p ""

  DISTRO=$(cat /etc/os-release | grep -i "NAME" | cut -d "=" -f2-)

  echo "Установка необходимых пакетов..."

  case $DISTRO in
    *"Debian"* | *"Ubuntu"* | *"Linux Mint"* )
      sudo apt-get install -y ${INSTALL_CMAKE:+cmake} ${INSTALL_PKG_CONFIG:+pkg-config} || { echo "Ошибка установки пакетов."; exit 1; }
      ;;
    *"Fedora"* | *"CentOS"* | *"Red Hat Enterprise Linux"* )
      sudo dnf install -y ${INSTALL_CMAKE:+cmake} ${INSTALL_PKG_CONFIG:+pkg-config} || { echo "Ошибка установки пакетов."; exit 1; }
      ;;
    *"Arch Linux"* | *"Manjaro"* | *"EndeavourOS"*)
      sudo pacman -S --noconfirm ${INSTALL_CMAKE:+cmake} ${INSTALL_PKG_CONFIG:+pkg-config} || { echo "Ошибка установки пакетов."; exit 1; }
      ;;
    *"openSUSE"* )
      sudo zypper install -y ${INSTALL_CMAKE:+cmake} ${INSTALL_PKG_CONFIG:+pkg-config} || { echo "Ошибка установки пакетов."; exit 1; }
      ;;
    *"Gentoo"* )
      [ "$INSTALL_CMAKE" = true ] && sudo emerge cmake || { echo "Ошибка установки cmake."; exit 1; }
      [ "$INSTALL_PKG_CONFIG" = true ] && sudo emerge pkg-config || { echo "Ошибка установки pkg-config."; exit 1; }
      ;;
    *"Slackware"* )
      [ "$INSTALL_CMAKE" = true ] && sudo slackpkg install cmake || { echo "Ошибка установки cmake."; exit 1; }
      [ "$INSTALL_PKG_CONFIG" = true ] && sudo slackpkg install pkg-config || { echo "Ошибка установки pkg-config."; exit 1; }
      ;;
    *"Mageia"* )
      [ "$INSTALL_CMAKE" = true ] && sudo urpmi cmake || { echo "Ошибка установки cmake."; exit 1; }
      [ "$INSTALL_PKG_CONFIG" = true ] && sudo urpmi pkg-config || { echo "Ошибка установки pkg-config."; exit 1; }
      ;;
    *"FreeBSD"* )
      [ "$INSTALL_CMAKE" = true ] && sudo pkg install cmake || { echo "Ошибка установки cmake."; exit 1; }
      [ "$INSTALL_PKG_CONFIG" = true ] && sudo pkg install pkg-config || { echo "Ошибка установки pkg-config."; exit 1; }
      ;;
    *"LFS"* )
      echo "Если у вас LFS, то поздравляю вы бог линукса, а во-вторых СКАЧАЙТЕ САМИ 'cmake и pkg-config'"
      exit 1
      ;;
    * )
      echo "Неизвестный дистр. Скачайте cmake и pkg-config сами."
      exit 1
      ;;
  esac
else
  echo "Оба пакета уже установлены. Установка не требуется."
fi
