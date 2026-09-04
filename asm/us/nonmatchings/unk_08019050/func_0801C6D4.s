.syntax unified
	.align 2, 0
	.global func_0801C6D4
	.thumb
	.thumb_func
	.type func_0801C6D4, %function
func_0801C6D4: @ 0801C6D4
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r0, _0801C6EC @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r4, #0x94
	lsls r4, r4, #0x01
	adds r0, r0, r4
	ldr r4, [r0, #0x00]
	cmp r4, #0x00
	bne _0801C6F0
	movs r0, #0x00
	b _0801C6FA
_0801C6EC: .4byte 0x02039B84
_0801C6F0:
	adds r0, r5, #0x0
	bl _call_via_r4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0801C6FA:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
