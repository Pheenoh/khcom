.syntax unified
	.align 2, 0
	.global task_bos_jf_shadow_0
	.thumb
	.thumb_func
	.type task_bos_jf_shadow_0, %function
task_bos_jf_shadow_0: @ 080C6EE0
	push {r4, lr}
	adds r4, r0, #0x0
	str r1, [r4, #0x0C]
	ldr r0, _080C6F08 @ =0x08B22EFE
	movs r1, #0xA0
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _080C6F0C @ =0x08B22EE4
	str r0, [r4, #0x08]
	ldr r0, _080C6F10 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C6F08: .4byte 0x08B22EFE
_080C6F0C: .4byte 0x08B22EE4
_080C6F10: .4byte 0x08F69BA4
.syntax divided
