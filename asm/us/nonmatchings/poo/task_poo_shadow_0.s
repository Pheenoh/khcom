.syntax unified
	.align 2, 0
	.global task_poo_shadow_0
	.thumb
	.thumb_func
	.type task_poo_shadow_0, %function
task_poo_shadow_0: @ 080CBF1C
	push {r4, lr}
	add sp, #-0x00C
	adds r4, r0, #0x0
	str r1, [sp, #0x000]
	movs r0, #0xA6
	str r0, [sp, #0x008]
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08000E64
	ldr r1, _080CBF44 @ =0x09EF4958
	adds r0, r4, #0x0
	mov r2, sp
	bl func_08000E14
	add sp, #0x00C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CBF44: .4byte 0x09EF4958
.syntax divided
