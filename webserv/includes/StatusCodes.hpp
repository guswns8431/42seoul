/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusCodes.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:51:18 by hyson             #+#    #+#             */
/*   Updated: 2022/08/17 18:52:15 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUSCODES_HPP
#define STATUSCODES_HPP

#include <string>

#include "./Utilizer.hpp"

class StatusCodes {
 private:
  StatusCodeMapper _mapper;

  StatusCodes(const StatusCodes& s);
  StatusCodes& operator=(const StatusCodes& s);

 public:
  StatusCodes(void);
  ~StatusCodes(void);

  const std::string& operator[](int code);
};

#endif
