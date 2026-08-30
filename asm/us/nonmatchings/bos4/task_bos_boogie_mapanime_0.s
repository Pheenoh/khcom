.syntax unified
	.align 2, 0
	.global task_bos_boogie_mapanime_0
	.thumb
	.thumb_func
	.type task_bos_boogie_mapanime_0, %function
task_bos_boogie_mapanime_0: @ 080DAB84
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _080DABA8 @ =0x096FE034
	bl func_080DDDDC
	adds r0, r4, #0x0
	adds r0, #0x0C
	ldr r1, _080DABAC @ =0x096FE04C
	bl func_080DDDDC
	adds r4, #0x18
	ldr r1, _080DABB0 @ =0x096FE064
	adds r0, r4, #0x0
	bl func_080DDDDC
	pop {r4}
	pop {r0}
	bx r0
_080DABA8: .4byte 0x096FE034
_080DABAC: .4byte 0x096FE04C
_080DABB0: .4byte 0x096FE064
.syntax divided
