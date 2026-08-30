.syntax unified
	.align 2, 0
	.global func_0810A51C
	.thumb
	.thumb_func
	.type func_0810A51C, %function
func_0810A51C: @ 0810A51C
	push {r4, lr}
	adds r4, r0, #0x0
	adds r3, r1, #0x0
	ldr r0, _0810A548 @ =0x01FFFFFF
	cmp r3, r0
	ble _0810A558
	ldr r0, _0810A54C @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x7C]
	movs r0, #0xFE
	lsls r0, r0, #0x08
	str r0, [r1, #0x04]
	ldr r0, _0810A550 @ =0x00015D00
	str r0, [r1, #0x08]
	movs r0, #0x00
	str r0, [r1, #0x0C]
	ldr r1, _0810A554 @ =0x09EF9E3C
	movs r0, #0xBA
	lsls r0, r0, #0x02
	adds r2, r4, r0
	adds r0, r3, #0x0
	b _0810A566
_0810A548: .4byte 0x01FFFFFF
_0810A54C: .4byte 0x02039B84
_0810A550: .4byte 0x00015D00
_0810A554: .4byte 0x09EF9E3C
_0810A558:
	ldr r0, _0810A578 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x2C
	ldr r1, _0810A57C @ =0x09EF9E3C
	movs r3, #0xBA
	lsls r3, r3, #0x02
	adds r2, r4, r3
_0810A566:
	bl func_08000E14
	movs r2, #0xB9
	lsls r2, r2, #0x02
	adds r1, r4, r2
	str r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_0810A578: .4byte 0x02039B84
_0810A57C: .4byte 0x09EF9E3C
.syntax divided
