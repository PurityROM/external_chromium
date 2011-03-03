// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_URL_REQUEST_URL_REQUEST_THROTTLER_HEADER_ADAPTER_H_
#define NET_URL_REQUEST_URL_REQUEST_THROTTLER_HEADER_ADAPTER_H_

#include <string>

#include "base/ref_counted.h"
#include "net/url_request/url_request_throttler_header_interface.h"

namespace net {

class HttpResponseHeaders;

// Adapter for the HTTP header interface of the URL request throttler component.
class URLRequestThrottlerHeaderAdapter
    : public URLRequestThrottlerHeaderInterface {
 public:
  explicit URLRequestThrottlerHeaderAdapter(net::HttpResponseHeaders* headers);
  virtual ~URLRequestThrottlerHeaderAdapter() {}

  // Implementation of URLRequestThrottlerHeaderInterface
  virtual std::string GetNormalizedValue(const std::string& key) const;
  virtual int GetResponseCode() const;

 private:
  const scoped_refptr<net::HttpResponseHeaders> response_header_;
};

}  // namespace net

#endif  // NET_URL_REQUEST_URL_REQUEST_THROTTLER_HEADER_ADAPTER_H_