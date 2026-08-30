.syntax unified
	.align 2, 0
	.global task_poo_map_1
	.thumb
	.thumb_func
	.type task_poo_map_1, %function
task_poo_map_1: @ 080CA210
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	bl func_080C9FBC
	adds r0, r6, #0x0
	bl func_080CA270
	ldr r5, _080CA250 @ =0x0203C40C
	ldrh r1, [r5, #0x00]
	ldr r4, _080CA254 @ =0x0203C3F8
	ldrh r2, [r4, #0x00]
	movs r0, #0x03
	bl func_08005244
	ldrh r1, [r5, #0x00]
	ldrh r2, [r4, #0x00]
	movs r0, #0x01
	bl func_08005244
	ldrh r1, [r5, #0x00]
	ldrh r2, [r4, #0x00]
	movs r0, #0x02
	bl func_08005244
	adds r6, #0x04
	adds r0, r6, #0x0
	bl func_08000EA4
	movs r0, #0x01
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_080CA250: .4byte 0x0203C40C
_080CA254: .4byte 0x0203C3F8
.syntax divided
