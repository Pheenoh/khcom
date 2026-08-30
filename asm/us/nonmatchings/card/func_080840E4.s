.syntax unified
	.align 2, 0
	.global func_080840E4
	.thumb
	.thumb_func
	.type func_080840E4, %function
func_080840E4: @ 080840E4
	push {r4, lr}
	movs r3, #0x00
	ldr r0, _08084110 @ =0x0203A858
	ldrh r0, [r0, #0x00]
	cmp r3, r0
	bge _08084106
	ldr r4, _08084114 @ =0x00000FFF
	ldr r2, _08084118 @ =0x0203A080
	adds r1, r0, #0x0
_080840F6:
	ldrh r0, [r2, #0x00]
	cmp r0, r4
	bne _080840FE
	adds r3, #0x01
_080840FE:
	adds r2, #0x02
	subs r1, #0x01
	cmp r1, #0x00
	bne _080840F6
_08084106:
	cmp r3, #0x00
	bgt _0808411C
	movs r0, #0x01
	b _0808411E
	.byte 0x00, 0x00
_08084110: .4byte 0x0203A858
_08084114: .4byte 0x00000FFF
_08084118: .4byte 0x0203A080
_0808411C:
	movs r0, #0x00
_0808411E:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
