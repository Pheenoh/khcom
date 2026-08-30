.syntax unified
	.align 2, 0
	.global func_0810C2F8
	.thumb
	.thumb_func
	.type func_0810C2F8, %function
func_0810C2F8: @ 0810C2F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	movs r5, #0x00
_0810C2FE:
	lsls r1, r5, #0x02
	movs r2, #0x81
	lsls r2, r2, #0x04
	adds r0, r6, r2
	adds r4, r0, r1
	ldr r1, [r4, #0x00]
	cmp r1, #0x00
	beq _0810C318
	ldr r0, _0810C328 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x40
	bl func_08000DE8
_0810C318:
	movs r0, #0x00
	str r0, [r4, #0x00]
	adds r5, #0x01
	cmp r5, #0x1F
	bls _0810C2FE
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0810C328: .4byte 0x02039B84
.syntax divided
