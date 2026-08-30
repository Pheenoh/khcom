.syntax unified
	.align 2, 0
	.global func_08083FE0
	.thumb
	.thumb_func
	.type func_08083FE0, %function
func_08083FE0: @ 08083FE0
	push {r4, r5, lr}
	movs r1, #0x00
	ldr r5, _08084008 @ =0x0203A858
	ldr r4, _0808400C @ =0x0203A080
	ldr r3, _08084010 @ =0x00000FFF
	ldr r2, _08084014 @ =0x000003E6
_08083FEC:
	lsls r0, r1, #0x01
	adds r0, r0, r4
	strh r3, [r0, #0x00]
	adds r0, r1, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, r2
	bls _08083FEC
	ldr r1, _08084018 @ =0x0000038F
	adds r0, r1, #0x0
	strh r0, [r5, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_08084008: .4byte 0x0203A858
_0808400C: .4byte 0x0203A080
_08084010: .4byte 0x00000FFF
_08084014: .4byte 0x000003E6
_08084018: .4byte 0x0000038F
.syntax divided
