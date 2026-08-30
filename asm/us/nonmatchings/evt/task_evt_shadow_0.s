.syntax unified
	.align 2, 0
	.global task_evt_shadow_0
	.thumb
	.thumb_func
	.type task_evt_shadow_0, %function
task_evt_shadow_0: @ 0801D000
	push {r4, lr}
	adds r4, r0, #0x0
	str r1, [r4, #0x04]
	ldr r0, _0801D03C @ =0x08B22BBC
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x08]
	ldr r0, _0801D040 @ =0x08B22CE4
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r4, #0x10]
	ldr r0, _0801D044 @ =0x08B22EFE
	movs r1, #0xA0
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x0C]
	ldr r0, _0801D048 @ =0x08F69BE4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801D03C: .4byte 0x08B22BBC
_0801D040: .4byte 0x08B22CE4
_0801D044: .4byte 0x08B22EFE
_0801D048: .4byte 0x08F69BE4
.syntax divided
