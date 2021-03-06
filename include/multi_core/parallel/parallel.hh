#ifndef ZINHART_PARALLELL_HH
#define ZINHART_PARALLELL_HH
#include <multi_core/serial/serial.hh> // for map 
//#include <multi_core/parallel/vectorized/vectorized.hh>
//#include <multi_core/parallel/thread_pool.hh>
namespace zinhart
{
  namespace multi_core
  {
	/*
	 * Asynchonous cpu methods. Since these are asynchrounous the called is expected to call resulsts[i].get() to ensure all threads have completed their work
	 * */
	namespace async
	{
	  template <class precision_type> 
		HOST void saxpy(const precision_type & a, precision_type * x, precision_type * y, 
			            const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0 
					   );
	  
	  template<class precision_type>
		HOST void copy(precision_type * in, precision_type * out, const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0);

	  template<class precision_type, class UnaryPredicate>
		HOST void copy_if(const precision_type * const in, precision_type * out, UnaryPredicate pred,
			              const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0
		                 );

	  template< class ForwardIt, class T, class container >
		HOST void replace(ForwardIt & first, const ForwardIt & last, const T & old_value, const T & new_value,
			              const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0
		                 );

	  template< class ForwardIt, class UnaryPredicate, class T, class container >
		HOST void replace_if(ForwardIt & first, const ForwardIt & last, UnaryPredicate p, const T& new_value,
			                 const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0
							);

	  template< class InputIt, class OutputIt, class T, class container >
		HOST void replace_copy(InputIt & first, const InputIt & last, OutputIt & output_it, const T& old_value, const T& new_value,
							   const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0
						      );

	  template< class InputIt, class OutputIt, class UnaryPredicate, class T, class container >
		HOST void replace_copy_if(const InputIt & first, const InputIt & last, OutputIt & output_it, UnaryPredicate p, const T& new_value,
								  const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0
								 );

	  template< class InputIt1, class InputIt2, class T, class container>
		HOST void inner_product(const InputIt1 & first1, const InputIt1 & last1, const InputIt2 & first2, T & value,
								const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0
							   );
	  template<class InputIt1, class InputIt2, class T, class BinaryOperation1, class BinaryOperation2, class container>
		HOST void inner_product(const InputIt1 & first1, const InputIt1 & last1, const InputIt2 & first2, T & value, BinaryOperation1 op1, BinaryOperation2 op2,
			                    const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0
							   );
	 
  	  template< class InputIt, class T, class container >
  		HOST void accumulate(const InputIt & first, const InputIt & last, T & init,
							 const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0
							);

	template < class InputIt, class UnaryFunction, class container >
	  HOST void for_each(const InputIt & first, const InputIt & last, UnaryFunction f,
		                 const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0
		                );
	
	template < class InputIt, class OutputIt, class UnaryOperation, class container >
	  HOST void transform(const InputIt & first, const InputIt & last, OutputIt & output_first, UnaryOperation unary_op,
		                  const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0
		                 );

	template < class BidirectionalIt, class Generator, class container >
	  HOST void generate(const BidirectionalIt & first, const BidirectionalIt & last, Generator g,
		                 const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0
						);

	template <class precision_type, class container>
	  HOST void kahan_sum(const precision_type * data, const std::uint32_t & data_size, precision_type & sum,
		                  const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0
		                 );
	
	template <class precision_type, class container>
	  HOST void neumaier_sum(const precision_type * data, const std::uint32_t & data_size, precision_type & sum,
		                     const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0
		                    );

	template <class precision_type,  class container, class binary_predicate>
	  HOST void kahan_sum(const precision_type * vec_1, const precision_type * vec_2, const std::uint32_t & data_size, 
						  precision_type & sum, 
						  binary_predicate bp, 
						  const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0 
		                  );
	
	template <class precision_type, class container, class binary_predicate>
	  HOST void neumaier_sum(const precision_type * data_1, const precision_type * data_2, const std::uint32_t & data_size, 
							 precision_type & sum, 
							 binary_predicate bp,
							 const std::uint32_t n_elements, const std::uint32_t n_threads = 1, const std::uint32_t thread_id = 0 
		                     );
	}// END NAMESPACE ASYNC
  }// END NAMESPACE MULTI_CORE
}// END NAMESPACE ZINHART
#include <multi_core/parallel/ext/parallel.tcc>
#endif
