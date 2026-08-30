.syntax unified
	.align 2, 0
	.global func_081025D4
	.thumb
	.thumb_func
	.type func_081025D4, %function
func_081025D4: @ 081025D4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r3, _08102608 @ =0x02035B68
	adds r1, r4, #0x0
	movs r2, #0x1F
_081025DE:
	ldrh r0, [r3, #0x00]
	strh r0, [r1, #0x00]
	adds r3, #0x02
	adds r1, #0x02
	subs r2, #0x01
	cmp r2, #0x00
	bge _081025DE
	ldr r3, _0810260C @ =0x02035BA8
	adds r1, r4, #0x0
	adds r1, #0x40
	movs r2, #0x01
_081025F4:
	ldrh r0, [r3, #0x00]
	strh r0, [r1, #0x00]
	adds r3, #0x02
	adds r1, #0x02
	subs r2, #0x01
	cmp r2, #0x00
	bge _081025F4
	pop {r4}
	pop {r0}
	bx r0
_08102608: .4byte 0x02035B68
_0810260C: .4byte 0x02035BA8
.syntax divided
