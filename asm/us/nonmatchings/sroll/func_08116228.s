.syntax unified
	.align 2, 0
	.global func_08116228
	.thumb
	.thumb_func
	.type func_08116228, %function
func_08116228: @ 08116228
	push {r4, lr}
	adds r3, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldrh r0, [r3, #0x1C]
	cmp r1, r0
	bcc _0811623C
	movs r1, #0x00
_0811623C:
	ldrh r0, [r3, #0x24]
	adds r0, r2, r0
	ldrh r4, [r3, #0x1E]
	cmp r0, r4
	ble _08116248
	movs r2, #0x00
_08116248:
	lsls r0, r1, #0x03
	strh r0, [r3, #0x20]
	strh r2, [r3, #0x22]
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
