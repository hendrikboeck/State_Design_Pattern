/*************************************************************************/
/* XRay State Machine (C++ Implementation)                               */
/* Copyright (C) 2020 by Hendrik Boeck                                   */
/*                                                                       */
/* This program is free software: you can redistribute it and/or modify  */
/* it under the terms of the GNU General Public License as published by  */
/* the Free Software Foundation, either version 3 of the License, or     */
/* (at your option) any later version.                                   */
/*                                                                       */
/* This program is distributed in the hope that it will be useful,       */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/* GNU General Public License for more details.                          */
/*                                                                       */
/* You should have received a copy of the GNU General Public License     */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>. */
/*************************************************************************/

/*
 * File: test.cpp
 * --------------
 * This file tests the functionality of the class XRayMachine and its
 * dependencies.
 */

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <vector>

#include "xraymachine.h"

#define HELP                                                    \
  "help            shows this message\n"                        \
  "script <path>   runs a script\n"                             \
  "exit            exits program\n"                             \
  "\n"                                                          \
  "turn_on         turns on the XRayMachine\n"                  \
  "turn_off        turns off the XRayMachine\n"                 \
  "cover_tube      covers x-raytube of the XRayMachine\n"       \
  "uncover_tube    uncovers the x-raytube of the XRayMachine\n" \
  "take_picture    takes a picture with the XRayMachine\n"

typedef char *str;

class Cli {
 public:
  Cli(std::string &&_buffer = "", std::string &&_executer = "#",
      std::ostream &_out = std::cout, std::istream &_in = std::cin)
      : buffer(std::move(_buffer)),
        executer(std::move(_executer)),
        out(_out),
        in(_in) {}
  ~Cli() = default;
  auto print() const -> void { out << buffer << " " << executer; }
  auto fetch() -> std::istream & {
    if (buffer != "") out << buffer << " ";
    out << executer << " ";
    return in;
  }

  std::string buffer;
  std::string executer;
  std::istream &in;
  std::ostream &out;
};

std::vector<std::string> str_split(const std::string &str,
                                   const std::string &delim) {
  std::vector<std::string> tokens;
  size_t prev = 0, pos = 0;
  do {
    pos = str.find(delim, prev);
    if (pos == std::string::npos) pos = str.length();
    std::string token = str.substr(prev, pos - prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + delim.length();
  } while (pos < str.length() && prev < str.length());
  return tokens;
}

// #define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))
typedef void (XRayMachine::*XRayMachineMemFn)(void);
const auto cmdmap = std::map<std::string, XRayMachineMemFn>(
    {{"turn_on", &XRayMachine::turn_on},
     {"turn_off", &XRayMachine::turn_off},
     {"cover_tube", &XRayMachine::cover_tube},
     {"uncover_tube", &XRayMachine::unconver_tube},
     {"take_picture", &XRayMachine::take_picture}});

auto process_cmds(XRayMachine &m, std::vector<std::string> cmds) -> void {
  if (cmdmap.find(cmds[0]) != cmdmap.end()) {
    (m.*cmdmap.at(cmds[0]))();
  } else if (cmds[0] == "script") {
    auto file = std::ifstream(cmds[1]);

    if (file.is_open()) {
      for (std::string line; std::getline(file, line);) {
        process_cmds(m, str_split(line, " "));
      }
      file.close();
    } else {
      std::cerr << "ERROR: File not found: '" << cmds[1] << "'" << std::endl;
    }
  } else if (cmds[0] == "help") {
    std::cout << HELP;
  } else if (cmds[0] == "exit") {
    exit(0);
  } else {
    std::cerr << "ERROR: could not find cli-command '" << cmds[0]
              << "'; type 'help' to see all commands;" << std::endl;
  }
}

auto main(int32_t argc, str *argv) -> int32_t {
  auto cli = Cli("xraymachine");
  auto m = XRayMachine();
  auto buffer = std::string();
  auto in = std::vector<std::string>();

  do {
    getline(cli.fetch(), buffer);
    in = str_split(buffer, " ");
    process_cmds(m, in);
  } while (in[0] != "exit");

  return 0;
}
