.syntax unified
	.align 2, 0
	.global task_poo_roo_footmark_0
	.thumb
	.thumb_func
	.type task_poo_roo_footmark_0, %function
task_poo_roo_footmark_0: @ 080CF144
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r0, _080CF174 @ =0x0004A700
	str r0, [r5, #0x0C]
	ldr r0, _080CF178 @ =0x00028E00
	str r0, [r5, #0x10]
	movs r4, #0x00
	str r4, [r5, #0x14]
	ldr r0, _080CF17C @ =0x09755A34
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl func_080026A4
	str r0, [r5, #0x00]
	str r4, [r5, #0x04]
	movs r0, #0x05
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080CF184
	ldr r0, _080CF180 @ =0x097559F4
	b _080CF186
	.byte 0x00, 0x00
_080CF174: .4byte 0x0004A700
_080CF178: .4byte 0x00028E00
_080CF17C: .4byte 0x09755A34
_080CF180: .4byte 0x097559F4
_080CF184:
	ldr r0, _080CF190 @ =0x09755A04
_080CF186:
	str r0, [r5, #0x08]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CF190: .4byte 0x09755A04
.syntax divided
