.syntax unified
	.align 2, 0
	.global task_bos_boogie_saku_2
	.thumb
	.thumb_func
	.type task_bos_boogie_saku_2, %function
task_bos_boogie_saku_2: @ 080DA9C8
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r0, _080DAA04 @ =0x00023F00
	bl func_0801AF1C
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r1, #0xA8
	lsls r1, r1, #0x08
	adds r0, r5, #0x0
	adds r2, r4, #0x0
	bl func_080DA954
	movs r1, #0xF8
	lsls r1, r1, #0x08
	adds r0, r5, #0x0
	adds r2, r4, #0x0
	bl func_080DA954
	movs r1, #0xA4
	lsls r1, r1, #0x09
	adds r0, r5, #0x0
	adds r2, r4, #0x0
	bl func_080DA954
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DAA04: .4byte 0x00023F00
.syntax divided
