.syntax unified
	.align 2, 0
	.global func_0801CC80
	.thumb
	.thumb_func
	.type func_0801CC80, %function
func_0801CC80: @ 0801CC80
	push {lr}
	ldr r0, _0801CCA8 @ =0x03007480
	ldr r0, [r0, #0x00]
	movs r1, #0x3C
	bl func_0811D7CC
	cmp r0, #0x00
	bne _0801CCA4
	ldr r0, _0801CCAC @ =0x02039BB0
	movs r1, #0xEE
	lsls r1, r1, #0x01
	adds r2, r0, r1
	ldr r1, [r2, #0x00]
	ldr r0, _0801CCB0 @ =0x00057E3E
	cmp r1, r0
	bhi _0801CCA4
	adds r0, r1, #0x1
	str r0, [r2, #0x00]
_0801CCA4:
	pop {r0}
	bx r0
_0801CCA8: .4byte 0x03007480
_0801CCAC: .4byte 0x02039BB0
_0801CCB0: .4byte 0x00057E3E
.syntax divided
