.syntax unified
	.align 2, 0
	.global task_btl_escape_0
	.thumb
	.thumb_func
	.type task_btl_escape_0, %function
task_btl_escape_0: @ 08030940
	push {r4, lr}
	adds r4, r0, #0x0
	movs r0, #0xB4
	lsls r0, r0, #0x07
	str r0, [r4, #0x18]
	ldr r0, _08030984 @ =0x08B1EB1C
	movs r1, #0x90
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _08030988 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	ldr r1, _0803098C @ =0x09EE11A4
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x08]
	ldr r0, [r1, #0x08]
	str r0, [r4, #0x0C]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x10]
	movs r0, #0x00
	str r0, [r4, #0x14]
	str r0, [r4, #0x1C]
	adds r1, r4, #0x0
	adds r1, #0x22
	strb r0, [r1, #0x00]
	strh r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08030984: .4byte 0x08B1EB1C
_08030988: .4byte 0x08F69BA4
_0803098C: .4byte 0x09EE11A4
.syntax divided
