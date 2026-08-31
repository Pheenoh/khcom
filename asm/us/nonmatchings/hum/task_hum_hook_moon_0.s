.syntax unified
	.align 2, 0
	.global task_hum_hook_moon_0
	.thumb
	.thumb_func
	.type task_hum_hook_moon_0, %function
task_hum_hook_moon_0: @ 0804C8FC
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _0804C93C @ =0x08B5A872
	movs r1, #0xC0
	lsls r1, r1, #0x04
	bl LoadObjTiles
	str r0, [r4, #0x00]
	movs r0, #0x00
	bl func_08007E68
	ldr r0, _0804C940 @ =0x08F6DC64
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	bl func_08007E7C
	ldr r0, [r4, #0x04]
	ldrb r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x00
	bl func_0801C298
	movs r0, #0x00
	strb r0, [r4, #0x0A]
	strh r0, [r4, #0x08]
	pop {r4}
	pop {r0}
	bx r0
_0804C93C: .4byte 0x08B5A872
_0804C940: .4byte 0x08F6DC64
.syntax divided
