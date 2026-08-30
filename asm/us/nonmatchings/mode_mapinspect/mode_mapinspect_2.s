.syntax unified
	.align 2, 0
	.global mode_mapinspect_2
	.thumb
	.thumb_func
	.type mode_mapinspect_2, %function
mode_mapinspect_2: @ 08109378
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r0, _081094BC @ =0x02035E4C
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, _081094C0 @ =0x02035E50
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, _081094C4 @ =0x02035E78
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, _081094C8 @ =0x02035E70
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, _081094CC @ =0x02035F54
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, _081094D0 @ =0x02035F70
	ldr r0, [r0, #0x00]
	bl func_080028C0
	movs r0, #0x00
	mov r8, r0
	ldr r0, _081094D4 @ =0x02035EA0
	mov r9, r0
	movs r7, #0x00
_081093BA:
	mov r0, r9
	adds r5, r7, r0
	adds r4, r7, #0x0
	movs r6, #0x02
_081093C2:
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	beq _081093CC
	bl func_08002C10
_081093CC:
	ldr r0, _081094D8 @ =0x02035ED0
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _081093DA
	bl func_080028C0
_081093DA:
	adds r5, #0x04
	adds r4, #0x04
	subs r6, #0x01
	cmp r6, #0x00
	bge _081093C2
	adds r7, #0x0C
	movs r0, #0x01
	add r8, r0
	mov r0, r8
	cmp r0, #0x03
	ble _081093BA
	ldr r0, _081094DC @ =0x02035F3C
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _081093FC
	bl func_08002C10
_081093FC:
	ldr r0, _081094E0 @ =0x02035F40
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08109408
	bl func_080028C0
_08109408:
	ldr r0, _081094E4 @ =0x02035F48
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08109414
	bl func_08002C10
_08109414:
	ldr r0, _081094E8 @ =0x02035F4C
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08109420
	bl func_080028C0
_08109420:
	ldr r0, _081094EC @ =0x02035E74
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0810942C
	bl func_08002C10
_0810942C:
	ldr r4, _081094F0 @ =0x02035F94
	ldr r0, [r4, #0x00]
	movs r1, #0x24
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl func_080009C4
	ldr r4, _081094F4 @ =0x02035F9C
	ldr r0, [r4, #0x00]
	movs r1, #0x5A
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl func_080009C4
	ldr r4, _081094F8 @ =0x02035FA4
	ldr r0, [r4, #0x00]
	ldr r1, _081094FC @ =0x02035FAA
	ldrh r1, [r1, #0x00]
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl func_080009C4
	ldr r4, _08109500 @ =0x02035FAC
	ldr r0, [r4, #0x00]
	ldr r1, _08109504 @ =0x02035FB2
	ldrh r1, [r1, #0x00]
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl func_080009C4
	ldr r4, _08109508 @ =0x02035FB4
	ldr r0, [r4, #0x00]
	ldr r1, _0810950C @ =0x02035FBA
	ldrh r1, [r1, #0x00]
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl func_080009C4
	ldr r5, _08109510 @ =0x02035FBC
	ldr r4, _08109514 @ =0x02035FC2
	movs r0, #0x00
	mov r8, r0
_0810948A:
	ldr r0, [r5, #0x00]
	ldrh r1, [r4, #0x00]
	bl func_08065AE0
	ldm r5!, {r0}
	bl func_080009C4
	adds r4, #0x02
	movs r0, #0x01
	negs r0, r0
	add r8, r0
	mov r0, r8
	cmp r0, #0x00
	bge _0810948A
	ldr r0, _08109518 @ =0x02035E28
	ldr r0, [r0, #0x00]
	bl func_080009C4
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_081094BC: .4byte 0x02035E4C
_081094C0: .4byte 0x02035E50
_081094C4: .4byte 0x02035E78
_081094C8: .4byte 0x02035E70
_081094CC: .4byte 0x02035F54
_081094D0: .4byte 0x02035F70
_081094D4: .4byte 0x02035EA0
_081094D8: .4byte 0x02035ED0
_081094DC: .4byte 0x02035F3C
_081094E0: .4byte 0x02035F40
_081094E4: .4byte 0x02035F48
_081094E8: .4byte 0x02035F4C
_081094EC: .4byte 0x02035E74
_081094F0: .4byte 0x02035F94
_081094F4: .4byte 0x02035F9C
_081094F8: .4byte 0x02035FA4
_081094FC: .4byte 0x02035FAA
_08109500: .4byte 0x02035FAC
_08109504: .4byte 0x02035FB2
_08109508: .4byte 0x02035FB4
_0810950C: .4byte 0x02035FBA
_08109510: .4byte 0x02035FBC
_08109514: .4byte 0x02035FC2
_08109518: .4byte 0x02035E28
.syntax divided
