.syntax unified
	.align 2, 0
	.global func_080A151C
	.thumb
	.thumb_func
	.type func_080A151C, %function
func_080A151C: @ 080A151C
	push {r4, lr}
	ldr r3, _080A1544 @ =0x02039BB0
	movs r1, #0x84
	lsls r1, r1, #0x01
	adds r0, r3, r1
	ldrb r2, [r0, #0x00]
	ldr r1, _080A1548 @ =0x09037FBA
	movs r4, #0xBC
	lsls r4, r4, #0x01
	adds r0, r3, r4
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r2, r0
	bge _080A154C
	movs r0, #0x00
	b _080A154E
	.byte 0x00, 0x00
_080A1544: .4byte 0x02039BB0
_080A1548: .4byte 0x09037FBA
_080A154C:
	movs r0, #0x01
_080A154E:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
