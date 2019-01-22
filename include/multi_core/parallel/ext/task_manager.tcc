#ifndef TASK_MANAGER_TCC
#define TASK_MANAGER_TCC
namespace zinhart
{
  namespace multi_core
  {
	HOST task_manager::task_manager(std::uint32_t n_threads)
	{ thread_pool.resize(n_threads); }
	
	HOST task_manager::~task_manager()
	{
	  /*
	  for(std::uint32_t task_id = 0; task_id < pending_tasks.size(); ++task_id)
		if(valid(task_id))
		  get(task_id);
	  */
	} 
/*
	template <class T>
	  HOST T task_manager<T>::get(std::uint64_t index)
	  { return pending_tasks.at(index).get(); }

	template <class T>
	  HOST bool task_manager<T>::valid(std::uint64_t index)
	  { return pending_tasks.at(index).valid(); }
*/
	  HOST void task_manager::resize(std::uint64_t n_threads)
	  { 
		thread_pool.resize(n_threads);
	  }
	  HOST std::uint64_t task_manager::size()const
	  { 
		return thread_pool.size();
	  }
/*
	template <class T>
	  template<class Callable, class ... Args>
	  HOST T task_manager<T>::push_wait(std::uint64_t priority, Callable && c, Args&&...args)
	  {
		thread_pool::tasks::task_future<T> pending_task{thread_pool.add_task(priority, std::forward<Callable>(c), std::forward<Args>(args)...)};
		return pending_task.get();
	  }
  
	template <class T>
	  template<class Callable, class ... Args>
	  HOST void task_manager<T>::push(std::uint64_t priority, Callable && c, Args&&...args)
	  {
		thread_pool::tasks::task_future<T> pending_task{thread_pool.add_task(priority, std::forward<Callable>(c), std::forward<Args>(args)...)};
		pending_tasks.push_back(std::move(pending_task));
	  }
*/
	HOST void task_manager::push(task_interface * t)
	{
	}
	
/*
	template <class T>
	  template<class Callable, class ... Args>
	  HOST void task_manager<T>::push_at(std::uint64_t at, std::uint64_t priority, Callable && c, Args&&...args)
	  {
		thread_pool::tasks::task_future<T> pending_task{thread_pool.add_task(priority, std::forward<Callable>(c), std::forward<Args>(args)...)};
		pending_tasks.at(at) = std::move(pending_task);
	  }
*/

	
  }// END NAMESPACE MULTI_CORE
}// END NAMESPACE ZINHART
#endif