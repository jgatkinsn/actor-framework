/******************************************************************************
 *                       ____    _    _____                                   *
 *                      / ___|  / \  |  ___|    C++                           *
 *                     | |     / _ \ | |_       Actor                         *
 *                     | |___ / ___ \|  _|      Framework                     *
 *                      \____/_/   \_|_|                                      *
 *                                                                            *
 * Copyright (C) 2011 - 2015                                                  *
 * Dominik Charousset <dominik.charousset (at) haw-hamburg.de>                *
 *                                                                            *
 * Distributed under the terms and conditions of the BSD 3-Clause License or  *
 * (at your option) under the terms and conditions of the Boost Software      *
 * License 1.0. See accompanying files LICENSE and LICENSE_ALTERNATIVE.       *
 *                                                                            *
 * If you did not receive a copy of the license files, see                    *
 * http://opensource.org/licenses/BSD-3-Clause and                            *
 * http://www.boost.org/LICENSE_1_0.txt.                                      *
 ******************************************************************************/

#ifndef CAF_DETAIL_DYNAMIC_MESSAGE_DATA_HPP
#define CAF_DETAIL_DYNAMIC_MESSAGE_DATA_HPP

#include <vector>

#include "caf/type_erased_value.hpp"

#include "caf/detail/message_data.hpp"

namespace caf {
namespace detail {

class dynamic_message_data : public message_data {
public:
  using elements = std::vector<type_erased_value_ptr>;

  dynamic_message_data();

  dynamic_message_data(const dynamic_message_data& other);

  dynamic_message_data(elements&& data);

  ~dynamic_message_data();

  const void* get(size_t pos) const override;

  void save(size_t pos, serializer& sink) const override;

  void load(size_t pos, deserializer& source) override;

  void* get_mutable(size_t pos) override;

  size_t size() const override;

  cow_ptr copy() const override;

  rtti_pair type(size_t pos) const override;

  std::string stringify(size_t pos) const override;

  uint32_t type_token() const override;

  void append(type_erased_value_ptr x);

  void add_to_type_token(uint16_t typenr);

  void clear();

private:
  elements elements_;
  uint32_t type_token_;
};

} // namespace detail
} // namespace caf

#endif // CAF_DETAIL_DYNAMIC_MESSAGE_DATA_HPP