#include "critic/test/art/ServiceUsing.h"

namespace art {
  namespace test {

    ServiceUsing::ServiceUsing(fhicl::ParameterSet const&,
                               art::ActivityRegistry& reg)
    {
      reg.sPostBeginJob.watch(this, &ServiceUsing::postBeginJob);
      wanted_->setValue(cached_value_);
    }

    void
    ServiceUsing::postBeginJob()
    {
      postBeginJobCalled_ = true;
      cached_value_ = 10;
      wanted_->setValue(cached_value_);
    }

  } // namespace test
} // namespace art

DEFINE_ART_SERVICE(art::test::ServiceUsing)
