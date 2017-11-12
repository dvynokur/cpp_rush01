//		Created by Denys Vynokurov and Roman Malkevych
//					Rush01, Piscine CPP

#include "ft_gkrellm.hpp"

int			main(void)
{
	Display		d;

	int		init_status = d.init();
	if (init_status == 0)
		d.run();

	d.close();

    return (0);
}
